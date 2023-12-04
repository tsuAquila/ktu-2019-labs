echo "Enter the choice:"
echo "(1)-Check Prime   (2)-Factorial"
read ch

case $ch in
1)
    echo -n "Enter number: "
    read n
    ((flag = 0))
    for ((i = 2; i <= n / 2; i++)); do
        if ((n % i == 0)); then
            ((flag = 1))
            break
        fi
    done
    if ((flag != 1)); then
        echo "Number is Prime."
    else
        echo "Number is not prime."
    fi
    ;;
2)
    echo -n "Enter number: "
    read n
    ((fact = 1))
    for ((i = n; i > 0; i--)); do
        ((fact = fact * i))
    done
    echo "Factorial of $n is $fact ."
    ;;
esac
