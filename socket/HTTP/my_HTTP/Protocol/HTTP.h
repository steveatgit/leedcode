#ifndef HTTP_H
#define HTTP_H

class HTTP {
public:
	HTTP(int fd);
	void handle();
	vdoi bad_request(int);
	void cat(int, FILE*);
	void cannot_execute(int);
	void error_die(const char*);
	void execute_cgi(int, const char *, const char*, const char*);
	int get_line(int, char*, int);
	void headers(int, const char*);
	void not_found(int);
	void serve_file(int, const char*);
	void unimplemented(int);

private:
	int client;
};

#endif
