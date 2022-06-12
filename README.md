# Homemamde Neural Network
### slowly but surely developing a neural network framework

## The Layer struct:
In this project, layers have a slightly different meaning, Layer is a class that has a vector for the values of its neuron and an matrix for the weights, whereas usually a layer refers exclusively to neurons.

It's constructor requires the desired lenght for the layer and the lenght of the next layer(0 for output layer), you may also give it a name for visualization purposes

	Layer(unsigned int size, unsigned int next_layer_size, string name = "Layer")
## Main network relatd functions:

	void layer_parser(Layer &A_layer, Layer &B_layer)
Gets the values from the neurons array and the weights matrix from A_layer class, calculate everything and inset the results in the B_layer neurons, can't be easyer than that

	void matrix_randomizer(vector<vector<double>> &data)
Set all values in a matrix to a random double betwenn 0.0 and 1.0

	void reset_matrix(vector<vector<double>> &matrix)
Set all values in a matrix to 0

	void reset_vector(vector<double> &vec)
Set all values in a vector to 0
	
## File handeling functions:

	vector<string> read_file(string file_name)
Get data from a file in the form of a vector of strings, where each line in the file becomes a string
	
	void write_file(vector<string> data, string file_name)
Get a vector of strings and write it to a file
	
	vector<vector<double>> dpkg(string data_file_path)
Get the matrix of floats directly from a file
	
	void repack(vector<vector<double>> data, string output_file)
Write a matrix of floats to a file, don't worry about formating
  
## Utilities functions:
  
	void print_vector(vector<string> vec)
Print a vector of strings
  
	void print_data(vector<double> vec)
Print a vector of floats, it's largest value will be printed in a blue color
  
	vector<string> split(string str, char delimiter)
Convert a string with words and spaces to a vector with each word, you may be able to use the optional delimiter witch has the default value of spaceBar, but i didn't tested it because who tf would need to do this

	vector<string> split(string str, char delimiter = ' ')
Convert a phrase with spaces to a vector of it's corresponding words, very simillar to explode() from PHP

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
verifies if and indice corresponds to the largest value in a vector
