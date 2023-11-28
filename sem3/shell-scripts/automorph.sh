if [ $# -ne 1 ]; then
	echo "Program needs exactly one argument"
	exit
fi

sqr=`expr $1 \* $1`

num=$1
len=0
while [ $num -ne 0 ]
do
	num=`expr $num / 10`
	len=`expr $len + 1`
done

rev=0
while [ $len -ne 0 ]
do
	r=`expr $sqr % 10`
	rev=`expr $rev \* 10 + $r`
	sqr=`expr $sqr / 10`
	len=`expr $len - 1`
done

ans=0
while [ $rev -ne 0 ]
do
	r=`expr $rev % 10`
	ans=`expr $ans \* 10 + $r`
	rev=`expr $rev / 10`
done


if [ $ans -eq $1 ];then
	echo "automorphic number"
else
	echo "not an automorphic number"
fi

