#include <iostream>
#include <vector>
#include <Phynx.h>

class Sandbox : public PX::Application
{

};

PX::Application* PX::CreateApplicationInstance()
{
	return new Sandbox();
}
