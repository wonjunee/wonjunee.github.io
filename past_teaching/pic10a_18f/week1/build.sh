# Remove the dedicated output directories
cd `dirname $0`

rm -rf build

# Cleaned up project
echo Cleaned up the project!

# Compile code.
mkdir -p build
cd build
cmake ..
make

