#include <stdio.h>

int main()
{
    int ul, ll, scount = 0, tscount = 0, max = 0, n; // αρχικοποιηση μεταβλητων΄
    printf("Enter your upper limit: "); // ανω, κατω ορια ευρεσης αριθμου 
    scanf("%d", &ul);
    if(ul>100000000){ //μεγιστο ανω οριου
        return 0;
    }
    printf("Enter your lower limit: ");
    if(ul < 1){ //ελαχιστο κατω οριου
        printf("0");
        return 0;
    }
    scanf("%d", &ll);

    for (n = ll; n <= ul; n++) { // αρχικοποιηση αριθμου n βασει των οριων
        int num = n; 
        scount = 0;

        while (num != 1) {  // εικασια collatz για καθε αριθμο n εντος οριων
            scount++; // step count +1 για καθε βημα
            if (num % 2 == 0) {
                num = num / 2;
            } else {
                num = 3 * num + 1;
            }
        }

        if (scount > tscount) { //ελεγχος για το εαν ο προσωρινος αριθμος βηματων ειναι μεγαλυτερος ετσι ωστε να εχουμε παντα ενα instance του μεγαλυτερου
            tscount = scount;
            max = n;
        }
    }

    printf("The number with the max steps is: %d\n", max);
    printf("With the steps being: %d\n", tscount);

    return 0;
} 
