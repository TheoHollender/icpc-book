`g++ -o out "$1/main.cpp"`
for inp in `find $1 -name *.in`; do
    out="${inp%.in}.out"
    echo "Checking $inp..."
    ./out < $inp > __local
    diff $out __local
done