ch=input("donner une chaine : ")
test= True
for i in range ( (len(ch)+1) // 2 ):
    if ch[i] != ch[-i-1] :
        test= False
        print ("la chaine n'est pas palindrome")
        break 

if test == True :
    print ("la chaine est palindrome")