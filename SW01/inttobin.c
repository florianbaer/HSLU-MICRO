int main(void) {

    int value;
    char c;
    int i;

    while (1)
    {
            printf("Geben Sie die Zahl ein: ");
                scanf("%d", &value);

                    printf("Binärzahl:");
                    for (i = sizeof(int) * 8; i > 0; i--) {
                                c = '0';
                                        if (value & (1 << (i - 1)))
                                        {
                                                        c = '1';
                                                                
                                        }
                                                printf("%c", c);
                                                    
                    }
                    printf("\n\n");
                    
    }
    return 0;

    
}
