if [ $# -le 1 ]; then
	echo "1 or more arguments required"
	exit
fi

sum=0
for i in $@
do
	sum=`expr $sum + $i`
done

echo "Sum = $sum"

