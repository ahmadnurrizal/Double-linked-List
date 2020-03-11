package main

import "fmt"

func main() {
	var angka int
	fmt.Scanln(&angka)
	angk
	for angka/2 != 0 {
		if angka%2 == 0 {
			fmt.Print(0, " ")
		} else {
			fmt.Print(1, " ")
		}
		angka = angka / 2
	}
	if angka == 1 {
		fmt.Print(1)
	}

}
