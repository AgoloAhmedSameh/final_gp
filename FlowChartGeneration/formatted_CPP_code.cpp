int s, e;
cout << "Enter start and end:";
cin >> s >> e;
for (int i = s; i <= e; ++i)
    {
        bool p = 1;
        if (i < 2)
{
            p = 0;
}
        for (int j = 2; j * j <= i && p; ++j)
            {
                if (i % j == 0)
{
                    p = 0;
}
            }
        if (p)
{
            cout << i << " ";
}
    }
return 0;
