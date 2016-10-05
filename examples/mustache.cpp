// Mustache template rendering sample

#include <rpoco/rpocojson.hpp>
#include <rpoco/mustache.hpp>

struct Person {
	char name[40];
	int age;
	double loyalty;
	bool child;

	RPOCO(name,age,child,loyalty);
};

struct Store {
	std::string name;
	std::vector<Person> emp;

	RPOCO(name,emp);
};

int main(int argc,char **argv) {

	// declare structure
	Store data;

	// sample data
	std::string sampleText="{ \"name\":\"Acme Store\" , \"emp\":[{\"name\":\"John Doe\",\"age\":12,\"child\":true,\"loyalty\":0.9},{\"name\":\"Jane Doe\",\"age\":34,\"child\":false,\"loyalty\":0.3},{\"name\":\"Bobby <>&\\\"' Tables\",\"age\":34,\"child\":false,\"loyalty\":0.01}] }";

	// parse in data
	rpocojson::parse(sampleText,data);

	// main template
	std::string mtpl="Store:{{name}} {{#emp}}{{> usertpl}}{{/emp}}";

	// user template via partial
	std::string usertpl="[escaped:{{name}} unescaped:{{{name}}} aged {{age}} is a {{#child}}child{{/child}}{{^child}}parent{{/child}} with loyalty {{loyalty}}]";

	// parse the partial template
	auto usertplfrag=rpoco::mustache::parse(usertpl);

	// create a partial resolver to support the rendering function (this could be more advanced and support f.ex. file loading)
	std::function<rpoco::mustache::multifragment*(std::string &name)> partialresolver=[&](std::string &partname){
		if (partname=="usertpl")
			return &usertplfrag;
		else
			return (rpoco::mustache::multifragment*)nullptr;
	};

	// render template with object data
	auto outputText=rpoco::mustache::parse(mtpl).render(data,partialresolver);

	// and print it
	printf("%s",outputText.c_str());

	return 0;
}

