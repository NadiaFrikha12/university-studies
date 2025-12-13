ch = str(input("donner une chaine : "))
ch1=""

for i in range (len(ch)-1): 
    ch1 += ch[len(ch) -i -1]


if (ch1 == ch ):
    print ("la chaine est palindrome")
else: 
    print ("la chaine n'est pas palindrome")

