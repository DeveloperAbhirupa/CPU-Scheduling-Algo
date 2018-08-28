a=10
b=20
val=`expr $a + $b`
echo "addition a+b: $val"
val=`expr $a -  $b`
echo "subtraction a-b: $val"
val=`expr $a \* $b`
echo "multiplication a*b: $val"
val=`expr $b / $a`
echo "division a/b: $val"
val=`expr $b % $a`
echo "remainder a+b: $val"
if [ $a -eq $b]
then
	echo "$a -eq $b a is equal to b"
else
	echo "$a -eq $b a is not equal to b"
fi




