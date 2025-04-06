// Name: 20. Valid Parentheses
// Topics: String, Stack
// Companies:
// - Turing
// - Ozon
// - EPAM Systems
// - BlackRock
// - ServiceNow
// - Zenefits
// - SAP
// - Infosys
// - Disney
// - Intel
// - Zoho
// - X
// - Huawei
// - Spotify
// - Intuit
// - Bloomberg
// - Walmart Labs
// - Epic Systems
// - Tesla
// - Expedia
// - Docusign
// - J.P. Morgan
// - Amazon
// - Yandex
// - eBay
// - Accenture
// - Apple
// - Swiggy
// - Wipro
// - Airbnb
// - Microsoft
// - IBM
// - LinkedIn
// - Meta
// - Siemens
// - Cognizant
// - Qualcomm
// - Salesforce
// - Uber
// - Google
// - Akuna Capital
// - Paytm
// - Morgan Stanley
// - Adobe
// - Yahoo
// - Nvidia
// - Tencent
// - Accolite
// - tcs
// - TikTok
// - Zeta
// - Barclays
// - Cisco
// - Samsung
// - American Express
// - Roblox
// - Tinkoff
// - Visa
// - Agoda
// - Netflix
// - Booking.com
// - PayPal
// - Goldman Sachs
// - DE Shaw
// - Citadel

package main

import "fmt"

func main() {
	str1 := "()"
	str2 := "()[]{}"
	str3 := "(]"
	str4 := "([])"

	fmt.Println(isValid(str1))
	fmt.Println(isValid(str2))
	fmt.Println(isValid(str3))
	fmt.Println(isValid(str4))
}

func isValid(s string) bool {
	// To find whether the brackets in the string are balanced, we'll use a stack
	// to keep track of the pairs. Opening brackets go into the stack. Closing
	// brackets are compared. If the top of the stack matches, then we're good
	// to continue. Otherwise, that pair is wrong and thus invalidates the string.

	bracketMap := map[byte]byte {
		'}': '{',
		']': '[',
		')': '(',
	}

	openBrackets := []byte{}

	for i := 0; i < len(s); i++ {
		ch := s[i]

		// Opening brackets go to the stack.
		if ch == '{' || ch == '[' || ch == '(' {
			openBrackets = append(openBrackets, ch)
			continue
		}

		stackSize := len(openBrackets)

		// If we find a closing bracket without any potential opening ones, or
		// the top of the stack doesn't match, then we can be sure the string
		// is malformed.

		if stackSize == 0 || openBrackets[stackSize - 1] != bracketMap[ch] {
			return false
		}

		// Pop the matching bracket and continue processing.
		openBrackets = openBrackets[:stackSize - 1]
	}

	// Make sure no bracket went unclosed.
	return len(openBrackets) == 0
}
