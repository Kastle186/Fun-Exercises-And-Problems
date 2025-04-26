// Name: 6. Zigzag Conversion
// Topics: String
// Companies:
// - Zopsmart
// - PayPal
// - ConsultAdd
// - Zoho
// - ServiceNow
// - Mitsogo
// - Oracle
// - Amazon
// - Uber
// - Infosys
// - Bloomberg
// - Microsoft
// - Intuit
// - Yahoo
// - Cisco
// - Apple
// - Adobe
// - Meta
// - Goldman Sachs

package main

import (
	"fmt"
	"bytes"
)

func main() {
	str12 := "PAYPALISHIRING"
	str3 := "A"

	zigzag1 := convert(str12, 3)
	zigzag2 := convert(str12, 4)
	zigzag3 := convert(str3, 1)

	fmt.Println("6. Zigzag Conversion")
	fmt.Println(zigzag1)
	fmt.Println(zigzag2)
	fmt.Println(zigzag3)
}

func convert(s string, numRows int) string {
	sLen := len(s)

	// If there is only one row, then the output is the same as the original
	// string. If there are equal or more rows to characters in the string, the
	// output is also the original string because each row will only have
	// one character.

	if numRows == 1 || numRows >= sLen {
		return s
	}

	var converted bytes.Buffer

	// TODO: Explain in detail why stepSize and midStep are calculated the way
	//       they are.

	for row := 0; row < numRows; row++ {
		stepSize := 2 * (numRows - 1)

		for i := row; i < sLen; i += stepSize {
			converted.WriteByte(s[i])

			if row == 0 || row == (numRows - 1) {
				continue
			}

			midStep := i + stepSize - (2 * row)

			if midStep < sLen {
				converted.WriteByte(s[midStep])
			}
		}
	}

	return converted.String()
}
