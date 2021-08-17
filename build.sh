chmod +x ./move.sh
empty_files=$(find . -type f -regex ".*\.c")
for file in "${empty_files[@]}"
do
    cp $file build/
done

empty_files=$(find . -type f -regex ".*\.h")
for file in "${empty_files[@]}"
do
    cp $file build/
done

empty_files=$(find . -type f -regex ".*\.asm")
for file in "${empty_files[@]}"
do
    cp $file build/
done


cd build
make