#include<iostream>
#include<fstream>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "please input src and dst path" << std::endl;
		return -1;
	}
	std::string src_path = argv[1];
	std::string dst_path = argv[2];
	int pos = src_path.rfind('\\');
	std::string name = src_path.substr(pos+1, std::string::npos);
	std::cout << "src img name:" << name.c_str() << std::endl;
	std::cout << "dst img path:" << (dst_path + name).c_str() << std::endl;
	int buff_size = 1024  * 1024 * 10;
	char* buffer = (char*)malloc(buff_size);
	std::ifstream ifs(src_path, std::ios::in| std::ios::binary);
	std::ofstream ofs(dst_path + name, std::ios::out | std::ios::binary);
	ifs.seekg(0, std::ios::end);
	int total = ifs.tellg();
	std::cout << "img total size:" << total/1024.0 << std::endl;
	ifs.seekg(0, std::ios::beg);
	int readCount = 0;
	int count = 0;
	while (count < total) {
		ifs.read(buffer, buff_size);
		readCount = ifs.gcount();
		std::cout << "read count:" << readCount << std::endl;
		count += readCount;
		ofs.write(buffer, readCount);
	}
	ifs.close();
	ofs.close();
	free(buffer);
	return 1;
}
