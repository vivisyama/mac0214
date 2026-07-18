t= int(input())
somas=[]
for i in range (t):
    valores= input().split()
    a= int(valores[0])
    b= int(valores[1])
    somas.append(a+b)
for i in range (t):
    print(somas[i])

    
