bool is_leap(unsigned year)
{
    return year % 4 == 0 && year % 100 ||
           year % 400 == 0;
}

unsigned max_days_in_month(unsigned month)
{
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return 28;
        default: return 0;
    }
}

bool valid_date(unsigned day, unsigned month, unsigned year)
{
    return day && month && year &&
           month <= 12 &&
           day <= max_days_in_month(month) + (is_leap(year) && month == 2);
}

int main()
{
    std::cout << valid_date(29, 2, 1900) << '\n'
              << valid_date(29, 2, 2000) << '\n';

    return 0;
}
