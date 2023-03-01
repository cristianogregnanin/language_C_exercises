 for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        for (int k = 0; k < n; k++)
        {
            for (int k = 0; k < n; k++)
            if (i == 0 || k == 0 || i == n - 1 || k == n - 1)
            {
                printf("* ");
            }
        }
        else
        {
            for (int k = 0; k < n; k++)
            else
            {
                if (k == 0 || k == n - 1)
                    printf("* ");
                else
                    printf("  ");
                printf("  ");
            }
        }

        printf("\n");
    }
    return 0;
