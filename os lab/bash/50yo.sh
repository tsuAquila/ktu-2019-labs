echo -n "Enter the name: "
read name
echo -n "Enter age: "
read age

((current_year = $(date +'%Y')))
((year = current_year - age + 50))

if ((year < current_year)); then
    echo "$name was 50 years old in $year."
else
    echo "$name will be 50 years old in $year."
fi
