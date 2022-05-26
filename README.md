# Homemamde Neural Network
### slowly but surely developing a neural network framework

## The Layer struct:
In this project, layers have a different meaning, Layer is a class that has a vector for it's neuron's values and a matrix for the weigts, nothing more, nothing less. 

	struct Layer
	{
	    vector<float> neurons;
	    vector<vector<float>> weights;
	};
## Main network relatd functions:

	void layer_parser(Layer &A_layer, Layer &B_layer)
Gets the values from the neurons array and the weights matrix from A_layer class, calculate everything and inset the results in the B_layer neurons, can't be easyer than that

	void matrix_randomizer(vector<vector<float>> &data)
Set all values in a matrix to a random float betwenn 0.0 and 1.0

	void reset_matrix(vector<vector<float>> &matrix)
Set all values in a matrix to 0

	void reset_vector(vector<float> &vec); // reset vector of floats
Set all values in a vector to 0
	
## File handeling functions:

	vector<string> read_file(string file_name)
Get data from a file in the form of a vector of strings, where each line in the file becomes a string
	
	void write_file(vector<string> data, string file_name)
Get a vector of strings and write it to a file
	
	vector<vector<float>> dpkg(string data_file_path)
Get the matrix of floats directly from file, can't be eazyer than that
	
	void repack(vector<vector<float>> data, string output_file)
Write a matrix of floats to a file, don't worry about formating
  
## Utilities functions:
  
	void print_vector(vector<string> vec)
Print a vector of strings, but if you didn't alreary understood that you better watch some videos from The Cherno
  
	void print_data(vector<float> vec)
Print a vector of floats
  
	vector<string> split(string str, char delimiter)
Convert a string with words and spaces to a vector with each word, you may be able to use the optional delimiter witch has the default value of spaceBar, but i didn't tested it because who tf would need to do this
