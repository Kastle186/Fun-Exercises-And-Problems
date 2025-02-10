package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 16 * 1024 * 1024)
    NTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)

    N := int32(NTemp)
    BTemp := strings.Split(strings.TrimSpace(readLine(reader)), " ")

    var B []int32

    for i := 0; i < int(N); i++ {
        BItemTemp, err := strconv.ParseInt(BTemp[i], 10, 64)
        checkError(err)
        BItem := int32(BItemTemp)
        B = append(B, BItem)
    }

    result := fairRations(B)
    fmt.Println(result)
}

func fairRations(subjects []int32) string {
	loaves := 0

	for i := 0; i < len(subjects) - 1; i++ {
		a := subjects[i]

		if a % 2 != 0 {
			subjects[i]++
			subjects[i+1]++
			loaves += 2
		}
	}

	if subjects[len(subjects)-1] % 2 == 0 {
		return strconv.Itoa(loaves)
	} else {
		return "NO"
	}
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()

    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
