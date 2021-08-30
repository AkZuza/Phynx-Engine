#pragma once
#include "Phynx/Core/Core.h"
#include "Phynx/Renderer/VertexArray.h"
#include "Phynx/Renderer/Buffer.h"
#include "Phynx/Renderer/Shader.h"

namespace PX {

	// base for the 2D and 3D renderer
	// might change in the future 
	// act as a wrapper over the APis as well as do
	// basic rendering
	// basically the middle man between Phnyx Engine API and the Graphics API(OpenGL, DirctX, Vulkan)
	class Renderer
	{
	public:
		// called by application class
		static void Init();
		// and get a pointer to the Graphics API implementation

		// Add function to set the API
		// void SetAPI()

		static void Clear(float r, float g, float b, float a) { m_RendererAPI->Impl_Clear(r, g, b, a); }

		// draw whatever is currently bound at that time
		static void Draw(uint32_t count) { m_RendererAPI->Impl_Draw(count); }
		static void DrawIndexed(uint32_t count) { m_RendererAPI->Impl_DrawIndexed(count); }

		static void Draw(uint32_t count, Shared<VertexBuffer> buffer, Shared<Shader> shader);
		static void DrawIndexed(uint32_t count, Shared<VertexArray> varray, Shared<Shader> shader);

	protected:
		// these virtual functions are called by the public static functions
		// they are implemeted by the respective Graphic APIs
		// Except for Init functions

		virtual void Impl_Clear(float r, float g, float b, float a) = 0;
		virtual void Impl_Draw(uint32_t count) = 0;
		virtual void Impl_DrawIndexed(uint32_t count) = 0;

	private:
		API m_API = API::OpenGL; // defulat api will be OpenGL
		inline static Shared<Renderer> m_RendererAPI = nullptr;

	};
}
