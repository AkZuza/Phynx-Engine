#pragma once
#include <vector>
#include "Phynx/Renderer/Layer.h"

namespace PX {

	class LayerManager
	{
	public:
		void PushLayer(Layer* layer)
		{
			m_Layers.push_back(layer);
		}

		void PopLayer()
		{
			m_Layers.pop_back();
		}

		void PushOverlayLayer(Layer* layer)
		{
			m_Layers.emplace(m_Layers.begin(), layer);
		}

		void PopOverlayLayer()
		{
			m_Layers.erase(m_Layers.begin());
		}

		std::vector<Layer*>& GetLayers() { return m_Layers; }

	private:
		std::vector<Layer*> m_Layers;
	};

}
