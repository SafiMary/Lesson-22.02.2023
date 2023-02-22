#include <iostream>
#include <windows.h>
#include <memory>

class Button {
public:
	virtual void paint() = 0;
	virtual ~Button(){}
};
class WinButton : public Button {
public:
	 void paint()override {
		std::cout << "Paint WinButton\n";
	}
};
class MacButton : public Button {
public:
	void paint() override {
		std::cout << "Paint MacButton\n";
	}
};
class Checkbox {
public:
	virtual void paint() = 0;
	virtual ~Checkbox(){}
};
class Wincheckbox :public Checkbox {
public:
	void paint()override {
		std::cout << "Paint Wincheckbox";
	}
};
class Maccheckbox :public Checkbox {
public:
	void paint()override {
		std::cout << "Paint Maccheckbox";
	}
};
class GUIfactory {
public:
	virtual std::shared_ptr<Button> createButton() = 0;
	virtual std::shared_ptr<Checkbox> createCheckbox() = 0;
	virtual ~GUIfactory(){}
};
class Winfactory : public GUIfactory {
public:
	std::shared_ptr<Button> createButton()override {
		return std::make_shared < WinButton>();
	 }
	std::shared_ptr<Checkbox> createCheckbox() override {
		return std::make_shared <Wincheckbox>();
	 }
};
class Macfactory : public GUIfactory {
public:
	std::shared_ptr<Button> createButton()override {
		return std::make_shared < MacButton>();
	}
	std::shared_ptr<Checkbox> createCheckbox() override {
		return std::make_shared <Maccheckbox>();
	}
};
class Application {
public:
	Application(std::shared_ptr<GUIfactory> factory) {
		_factory = factory;
	}
	void createUI() {
		_button = _factory->createButton();
		_checkbox = _factory->createCheckbox();
	}
	void paint() {
		_button->paint();
		_checkbox->paint();
	}
private:
	std::shared_ptr<GUIfactory> _factory;
	std::shared_ptr<Button> _button;
	std::shared_ptr<Checkbox> _checkbox;
};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string config;
	std::shared_ptr<GUIfactory> factory;
	std::cout << "Enter platform (Mac,Windows)\n";
	std::cin >> config;
	if (config == "Mac"){
		factory = std::make_shared<Macfactory>();
}
else if (config == "Windows") {
	factory = std::make_shared<Winfactory>();
	}
	std::shared_ptr<Application> app = std::make_shared<Application>(factory);
	app->createUI();
	app->paint();
	std::string s;
	std::cin >> s;
















}