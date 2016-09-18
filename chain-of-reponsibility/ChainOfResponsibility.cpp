/*
 * C++ Design Patterns: Chain of Responsibility
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT licence
 * (for more details see LICENCE)
 *
 */
#include <iostream>

/*
 * Handler
 * defines an interface for handling requests and
 * optionally implements the successor link
 */
class Handler {
public:
  virtual void setHandler(Handler *s) {
    successor = s;
  }

  virtual void handleRequest() {
    if (successor != 0) {
      successor->handleRequest();
    }
  }
  // ...

private:
  Handler *successor;
};

/*
 * Concrete Handlers
 * handle requests they are responsible for
 */
class ConcreteHandler1 : public Handler {
public:
  bool canHandle() {
    // ...
    return false;
  }

  virtual void handleRequest() {
    if (canHandle()) {
      std::cout << "Handled by Concrete Handler 1" << std::endl;
    } else {
      std::cout << "Cannot handle by Handler 1" << std::endl;
      Handler::handleRequest();
    }
    // ...
  }
  // ...
};

class ConcreteHandler2 : public Handler {
public:
  bool canHandle() {
    // ...
    return true;
  }

  virtual void handleRequest() {
    if (canHandle()) {
      std::cout << "Handled by Handler 2" << std::endl;
    } else {
      std::cout << "Cannot handle by Handler 2" << std::endl;
      Handler::handleRequest();
    }
    // ...
  }

  // ...
};


int main()
{
  ConcreteHandler1 handler1;
  ConcreteHandler2 handler2;

  handler1.setHandler(&handler2);
  handler1.handleRequest();

  return 0;
}