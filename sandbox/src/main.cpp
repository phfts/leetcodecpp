#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <fstream>
#include <iostream>
#include <chrono>

int compress()
{

    std::ifstream sourceFile("input.txt", std::ios::binary);
    std::ofstream targetFile("compressed_output.txt", std::ios::binary);

    boost::iostreams::filtering_ostream out;
    out.push(boost::iostreams::zlib_compressor());
    out.push(targetFile);

    boost::iostreams::copy(sourceFile, out);

    sourceFile.close();
    targetFile.close();

    return 0;
}


int readfile() {
    // Abra o arquivo em modo binário
    std::ifstream file("input.txt", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    // Determine o tamanho do arquivo
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Aloque memória suficiente
    std::vector<char> buffer(fileSize);

    // Leia o conteúdo do arquivo para a memória
    file.read(buffer.data(), fileSize);

    // Feche o arquivo
    file.close();

    // Acesse e imprima o conteúdo do arquivo
    for (char character : buffer) {
        // std::cout << character;
    }

    return 0;
}

int main()
{
    std::cout << "Starting " << std::endl;
    auto start = std::chrono::steady_clock::now();

    readfile();

    auto end = std::chrono::steady_clock::now();

    // Calcula a diferença de tempo em milissegundos
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Imprime o tempo decorrido em milissegundos
    std::cout << "Tempo decorrido: " << duration.count() << " ms\n";

    return 0;
}