# Clear testcases:
rm -f *.inp
rm -f *.cor


# Generate testcases:
echo -e "3
10 7 4
0 7 4
-1 -1  2" > sample-1.inp

echo -e "3
8 5 3
8 0 0
4 4 0" > sample-2.inp

echo -e "3
8 5 3
8 0 0
4 3 1" > sample-3.inp

echo -e "5
50 50 12 8 2
50 50 0 0 0
-1 31 -1 -1 -1" > sample-4.inp

echo -e "5
50 50 50 50 1
50 0 0 0 0
-1 25 -1 -1 -1" > sample-5.inp

for i in {1..8}
do
	python genera.py 654322"$i" > test-"$i".inp
done

for i in {9..12}
do
	python genera.py 654322"$i"X > test-"$i".inp
done

sleep 2

# Not working properly :(
# jutge-make-problem

# Generate corrections:
for file in *-*.inp
do
	name=$(echo "$file" | cut -f 1 -d '.')
	echo "Executing $file..."
	python solution.py < "$name".inp > "$name".cor
done

echo "DONE!"
