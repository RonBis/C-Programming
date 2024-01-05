if [ $# -ne 1 ]; then
        echo "Program needs exactly one argument"
        exit
fi

num=$1
square=`expr $num \* $num`

c=0
while [ $num -ne 0 ]
do
    c=`expr $c + 1`
    num=`expr $num / 10`
done

let divisor=10**$c
check=`expr $square % $divisor`

if [ $check -eq $1 ];then
    echo automorphic number
else
    echo not automorphic number
fi
