rm -rf build/
mkdir build
empty_files=$(find . -type f -regex ".*\.c")
for file in "${empty_files[@]}"
do
    cp $file build/ 2>/dev/null
done

empty_files=$(find . -type f -regex ".*\.h")
for file in "${empty_files[@]}"
do
    cp $file build/ 2>/dev/null
done

empty_files=$(find . -type f -regex ".*\.asm")
for file in "${empty_files[@]}"
do
    cp $file build/ 2>/dev/null
done

cp makefile build/
cp link.ld build/

cd build
make
make run
