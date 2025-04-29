// Name: 383. Ransom Note
// Topics: Hash Table, String, Counting
// Companies:
// - Disney
// - Karat
// - Spotify
// - Pinterest

package main

import "fmt"

func main() {
	note1 := "a"
	mag1 := "b"

	note2 := "aa"
	mag2 := "ab"

	note3 := "aa"
	mag3 := "aab"

	fmt.Println("383. Ransom Note")
	fmt.Println(canConstruct(note1, mag1))
	fmt.Println(canConstruct(note2, mag2))
	fmt.Println(canConstruct(note3, mag3))
}

func canConstruct(ransomNote string, magazine string) bool {
	letters := make(map[rune]int)

	// First, we need to record all the letters that we have available to construct
	// the note.

	for _, chr := range magazine {
		letters[chr] += 1
	}

	// And now, we use those letters. If at some point we need a letter we don't
	// have (anymore of), then we can define it is not possible to construct this
	// note with this magazine.

	for _, chr := range ransomNote {
		if letters[chr] > 0 {
			letters[chr] -= 1
		} else {
			return false
		}
	}

	return true
}
