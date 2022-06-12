# Homemamde Neural Network

### Slowly but surely, developing a neural network framework

## Layer struct:

In this project, layers have a slightly different meaning. Layer is a struct
with a vector for the values of its neurons and a matrix for the weights,
whereas usually, a layer refers exclusively to neurons.

Its constructor requires the desired length for the layer and the length of the
next layer(0 for the output layer); you may also give it a name for
visualization purposes

    Layer(unsigned int size, unsigned int next_layer_size, string name = "Layer")

## Main network-related functions:

    void layer_parser(Layer &A_layer, Layer &B_layer)

Gets the values from the neurons array and the weights matrix from the A_layer
struct, then calculates everything and inserts the results in the B_layer
neurons

    void matrix_randomizer(vector<vector<double>> &data)

Set all values in a matrix to a random double between 0.0 and 1.0

    void reset_matrix(vector<vector<double>> &matrix)

Set all values in a matrix to 0

    void reset_vector(vector<double> &vec)

Set all values in a vector to 0

## File handling functions:

    vector<string> read_file(string file_name)

Get data from a file in the form of a vector of strings, where each line in the
file becomes a string void write_file(vector<string> data, string file_name) Get
a vector of strings and write it to a file vector<vector<double>> dpkg(string
data_file_path) Get the matrix of doubles directly from a file void
repack(vector<vector<double>> data, string output_file) Write a matrix of
doubles to a file

## Utilities functions:

    void print_vector(vector<string> vec)

Print a vector of strings

    void print_data(vector<double> vec)

Print a vector of doubles. The largest value will be printed in a blue color

    vector<string> split(string str, char delimiter)

Convert a string with words and spaces to a vector with each word, you may be
able to use the optional delimiter, which has the default value of spaceBar

    vector<string> split(string str, char delimiter = ' ')

Converts a phrase with spaces to a vector of its corresponding words, which is
very similar to explode() from PHP

    vector<double> multiply_scalar_by_vector(vector<double> vec, double scalar)

Multiply all values in a vector by the given number

    void print_matrix(vector<vector<double>> matrix)

Print a matrix of doubles

    vector<vector<double>> matrix_transponser(vector<vector<double>> matrix)

Transpose a matrix

    double average(vector<double> vec)

Get the average of the values in a vector

    double absolute_difference(double test_set[], vector<double> values)

compare two vectors and return the total difference between them

    bool is_largest(vector<double> vec, unsigned int indice)

verifies if and indices correspond to the largest value in a vector
