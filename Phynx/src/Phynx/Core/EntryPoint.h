#pragma once

int main()
{
	auto app = PX::CreateApplicationInstance();
	app->Start();
	app->Run();
	app->Shutdown();
	delete app;

	return 0;
}
