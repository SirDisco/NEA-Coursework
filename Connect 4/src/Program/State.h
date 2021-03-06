#pragma once

#include <SFML/Graphics.hpp>

namespace Connect
{
	class Button;

	// Abstract State class used to allow for polymorphism
	// to store all states in a single data structure easily
	class State
	{
	public:
		State() {};
		virtual ~State() {};
	
	public:
		// Used to initialize any values that need to be created a single time
		// Cannot take parameters so the construcutor of the base class must be used
		virtual void Initialize() = 0;
		// Used to update any values that may need to change based on the user
		// Perhaps an optimization can be made to only run this when something has actually changed
		virtual void Execute() = 0;
		// Used to draw all the objects in the state will be run every frame
		// Unless there is an optimization but this will be hard to communicate with main.cpp
		virtual void Draw() = 0;

		// Used to give this state the handle to the window to draw stuff
		inline void SetWindow(sf::RenderWindow* window) { m_Window = window; }

	// Common Button Functions
	protected:
		void PopState();
		void RemoveAllStates();
		void PushConfirmExitState();
	
	protected:
		static sf::RenderWindow* m_Window;

	public:
		Button* recentButton = nullptr;
	};
}