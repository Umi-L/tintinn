#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <switch.h>
#include <entt.hpp>

#include "Input.hpp"

int main(int argc, char* args[])
{

	// Initialize sockets
	socketInitializeDefault();
	nxlinkStdio();

	printf("--Application Started--\n");

	printf("--Mounting romfs--\n");

	//fetch romfs files and mount
	romfsInit();
    chdir("romfs:/");

	printf("--Initializing Input--\n");

	Input::init();

	printf("Initializing Variables\n");

	entt::registry registry;

	printf("--Main loop Starting--\n");

	//main loop
	bool running = true;
	while (running)
	{
		u64 kDown = Input::update();

		if (kDown & HidNpadButton_Plus)
            running = false;
	}

	printf("--Cleanup Started--\n");

	Input::cleanup();

	printf("--Completed, Quitting--\n");

	//close socket
    socketExit();

	return 0;
}
