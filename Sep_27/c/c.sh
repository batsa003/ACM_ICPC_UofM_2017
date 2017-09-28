
rm -f myout*
rm -f "a.out"

g++ -std=c++11 -Wall -Wextra -Wshadow -O2 -Wconversion -fsanitize=address C.cpp

if [[ -f "./a.out" ]]; then

  for ((i=1; i<=1000; i++)); do
    if [[ -f "./in$i" ]]; then
      ./a.out < "in$i" > "myout$i"
          cat "myout$i"
    fi
  done

  echo difference

  for ((i=1; i<=1000; i++)); do
    if [[ -f "./in$i" ]]; then
      diff "myout$i" "out$i" 
    fi
  done

fi

