n = int(input())
left = 0
right = n
while(left < right):
    med = (left + right +1)// 2
    if med*(med+1)//2 + med*(med+1)*(med+2)//6 - 1 <= n:
        left = med
    else:
        right = med - 1
print(left)