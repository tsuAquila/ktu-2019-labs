echo -n "Enter the number: "
read n

((temp=n))
((d=0))
while ((temp != 0))
do
    ((d=d+1))
    ((temp=temp/10))
done

((temp=n))
((sum=0))

while ((temp != 0))
do
    ((digit=temp%10))
    ((sum = sum + digit**d))
    ((temp = temp/10))
done

if ((sum == n))
then
    echo "Number is armstrong."
else
    echo "Number is not armstrong."
fi