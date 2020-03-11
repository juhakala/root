echo "USERS:"
echo ""
cat /etc/passwd | grep /home | cut -d ":" -f1
echo ""
echo "PICK ONE TO DELETE"
read name
check=`cat /etc/passwd | grep $name`
if [ "$check" != "$NULL" ]; then
	if [ "$(pgrep -u $name)" != "$NULL" ]; then
		sudo kill -9 $(pgrep -u $name)
		fi
	sudo userdel -r $name
else
	echo "user not found"
fi