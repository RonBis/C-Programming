if [ $# -ne 1 ]
then
	echo "Provide 1 argument"
	exit
fi	

i=2
while [ $i -le `expr $1 / 2` ]
do
	if [ `expr $1 % $i` -eq 0 ]
	then
		echo "not a prime"
		exit
	fi
	i=`expr $i + 1`
done

echo "prime"

