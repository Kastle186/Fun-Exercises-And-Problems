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
    firstMultipleInput := strings.Split(strings.TrimSpace(readLine(reader)), " ")

    nTemp, err := strconv.ParseInt(firstMultipleInput[0], 10, 64)
    checkError(err)
    n := int32(nTemp)

    mTemp, err := strconv.ParseInt(firstMultipleInput[1], 10, 64)
    checkError(err)
    m := int32(mTemp)

    var topic []string

    for i := 0; i < int(n); i++ {
        topicItem := readLine(reader)
        topic = append(topic, topicItem)
    }

    result := acmTeam(topic, m)

    for _, resultItem := range result {
        fmt.Println(resultItem)
    }
}

func acmTeam(topics []string, numTopics int32) []int32 {
	maxTopics := -1
	numTeams := 0

	// We have to check all the possible combinations to figure out which one(s)
	// fulfill the most topics known.

	for i := 0; i < len(topics) - 1; i++ {
		for j := i + 1; j < len(topics); j++ {
			member1 := topics[i]
			member2 := topics[j]
			teamTopics := 0

			// We are guaranteed that all strings are of the same length.

			for k := int32(0); k < numTopics; k++ {
				// The number 49 is the ASCII Code for '1'.
				if member1[k] == 49 || member2[k] == 49 {
					teamTopics++
				}
			}

			// If this combination knows more topics than the one that we had that
			// knew most, then we set this as the new threshold, and we begin
			// counting again. If they are equal, then we've found another pairing
			// that knows the most topics and we only increment the teams counter.

			if teamTopics > maxTopics {
				maxTopics = teamTopics
				numTeams = 1
			} else if teamTopics == maxTopics {
				numTeams++
			}
		}
	}

	result := []int32{int32(maxTopics), int32(numTeams)}
	return result
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
