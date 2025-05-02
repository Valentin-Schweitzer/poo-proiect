#!/usr/bin/bash

# default values
CPPCHECK_VER=2.14.2
CMAKE_BUILD_DIR=build
CMAKE_OPTS=()

while getopts ":b:o:v:" opt; do
  case "${opt}" in
    b) CMAKE_BUILD_DIR="${OPTARG}" ;;
    o) IFS=" " read -r -a CMAKE_OPTS <<< "${OPTARG}" ;;
    v) CPPCHECK_VER="${OPTARG}" ;;
    *)
      printf "Unknown option %s; available options: \n\
        -b (build dir)\n\
        -o (cmake opts)\n\
        -v (cppcheck version)\n" "${opt}"
      exit 1
    ;;
  esac
done

# clean up previous
rm -rf cppcheck
wget "https://github.com/danmar/cppcheck/archive/refs/tags/${CPPCHECK_VER}.zip"
unzip -q "${CPPCHECK_VER}.zip"
rm "${CPPCHECK_VER}.zip"
mv "cppcheck-${CPPCHECK_VER}" cppcheck

cd cppcheck || { echo "Eroare cd"; exit 1; }

# 🧼 remove the build directory if it exists
rm -rf "${CMAKE_BUILD_DIR}"

cmake -S . -B "${CMAKE_BUILD_DIR}" "${CMAKE_OPTS[@]}"
cmake --build "${CMAKE_BUILD_DIR}" -j$(nproc)
