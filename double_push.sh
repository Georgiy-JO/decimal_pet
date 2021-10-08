#don't forget to commit (unless u use option 9)
VAR_FILE="double_push.variables.txt"
VAR_branch="feature/JO_RK_mainfunctions"           
#1)"feature/JO_RK_base"
#2)"feature/JO_RK_servicefunctions_2"  
old_tec_com=$(<"$VAR_FILE")

if [ "$1" -eq 1 ]
then
  git push origin $VAR_branch
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push hub $VAR_branch
elif [ $1 -eq 0 ]
then
  git push origin develop
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push hub develop
elif [ $1 -eq 9 ]
then
  new_tec_com=$((old_tec_com + 1))
  echo "$new_tec_com" > $VAR_FILE
  git add src $VAR_FILE
  git commit -m"Technical commit #"$new_tec_com": Minor changes."
  git push origin $VAR_branch
  echo ◑ ◔
  echo ╔═╗
  echo ║▓▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
  echo ╚═╝
  git push hub $VAR_branch
else
  echo ERROR command
fi



