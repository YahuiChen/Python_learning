int n;
typedef int array[1000];
/*@
requires \length(a) == n && n == 1000;
ensures  (\forall integer i : [0..n-2]. a[i] <= a[i+1]) && \length(a) == n;
*/
void InsertionSort(array a)
{
    int temp;
    int i,j;
    /*@ loop invariant
        n == 1000 && i == 1  && \length(a) == n 
        || n == 1000 && 1 < i < n && \length(a) == n &&
        (\forall integer k : [0..i-1]. a[k] <= a[k+1])
        || n == 1000 && i == n && \length(a) == n &&
        (\forall integer k : [0..i-2]. a[k] <= a[k+1]);
    */
    for (i = 1; i < n; i = i + 1)
    {           
        temp = a[i];
        /*@ loop invariant
            n == 1000 && i == 1  && j == i && \length(a) == n || 
            n == 1000 && i == 1  && j < i && \length(a) == n && a[0] == a[1] ||

            n == 1000 && 1 < i < n && j == i  && \length(a) == n &&
            (\forall integer k : [0..i-1]. a[k] <= a[k+1]) ||

            n == 1000 && 1 < i < n && 0 < j < i && \length(a) == n &&
            (\forall integer k : [0..i-1]. a[k] <= a[k+1]) &&
            (\forall integer k : [j..i]. a[k] > temp) &&
            (\forall integer k : [0..j-1]. a[k] <= temp) ||

            n == 1000 && 1 < i < n && j == 0 && \length(a) == n &&
            (\forall integer k : [1..i-1]. a[k] <= a[k+1]) && a[0] == a[1] ;            
        */
        for ( j = i; j > 0 && a[j - 1] > temp; j = j - 1)
        {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
    return;
}