double pow(int base, double input)
{
    double output = input;

    for (int i = 0; i < base; i++)
    {
        output = output * output;
    }
    return output;
}