if [ $# -ne 2 ]
then
	echo "Provide 2 arguments"
	exit
fi	

iter=$1
while [ $iter -le $2 ]
do
	i=2
	flag=0
	
	while [ $i -le `expr $iter / 2` ]
	do
		if [ `expr $iter % $i` -eq 0 ]
		then
			flag=1 # not prime
			break
		fi
		i=`expr $i + 1`
	done
	
	if [ $flag -ne 1 ]
	then
		echo $iter
	fi
	
	iter=`expr $iter + 1`
done

