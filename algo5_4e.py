def findDiag(n):
    left = 1
    right = n
    while(left <= right):
        mid = left + (right-left+1)//2
        minNum = (mid - 1) * (mid)//2
        maxNum = mid * (mid+1)//2
        if(maxNum < n):
            left = mid
        elif(minNum+1 > n):
            right = mid - 1
        else:
            return mid
    return left


n = int(input())
diag = findDiag(n)
maxNum = diag * (diag+1)//2
a = 1 + (maxNum - n)
b = diag - (maxNum - n)
s = '{}/{}'.format(a,b)
if(diag%2 != 0): s = '{}/{}'.format(b,a)
print(s)
