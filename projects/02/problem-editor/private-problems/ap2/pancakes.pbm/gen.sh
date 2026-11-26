# Clear testcases:
rm -f *.inp
rm -f *.cor


# Generate testcases:
echo -e "3\n3 1 2" > sample-1.inp

echo -e "4\n3 2 1 4" > sample-2.inp

for i in {3..4}
do
	python genera.py 612345"$i" > sample-"$i".inp
done

for i in {1..12}
do
	python genera.py 654321"$i" > test-"$i".inp
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
