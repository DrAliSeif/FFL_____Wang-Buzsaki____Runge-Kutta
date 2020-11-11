# FFL Wang-Buzsaki Runge-Kutta
Wang-Buzsaki model with Runge-Kutta 4th Order Method for three inhibitory neurons for connect to the FFL

## Graph theory

In mathematics, and more specifically in graph theory, a vertex (plural vertices) or node is the fundamental unit of which graphs are formed: an undirected graph consists of a set of vertices and a set of edges (unordered pairs of vertices), while a directed graph consists of a set of vertices and a set of arcs (ordered pairs of vertices).

<p align="center">
 <img src="https://raw.githubusercontent.com/aliseif321/FFL_____Wang-Buzsaki_Runge-Kutta/main/Pictures/Network-motifs-found-in-biological-networks-The-feed-forward-loop-bi-fan-and-biparallel.png" width="300" height="290">
 </p>
 


## Feed Forward Loop
Feed forward loop (FFL) motif is one of the most significant one in both E. coliand yeast. The FFL is composed of a transcription factor X, which regulates a second transcription factor Y. X and Y both bind the regulatory region of target gene Z and jointly modulate its transcription rate. The FFL has three transcription interactions. Each of these can be either positive (activation) or negative (repression). For a three node pattern there exitst 13 possible ways to create a directed (with arrows of definite direction) subgraph.

<p align="center">
 <img src="https://raw.githubusercontent.com/aliseif321/FFL_____Wang-Buzsaki_Runge-Kutta/main/Pictures/Feedforwardloop.gif" >
 </p>
  

  
  <p align="center">
  <img src="https://raw.githubusercontent.com/aliseif321/FFL_____Wang-Buzsaki_Runge-Kutta/main/Pictures/Wang-Buzsaki_Runge-Kutta_FFL.png">
</p>

## Wang-Buzsaki
The Wang-Buzsaki model uses the Hodgkin-Huxley formalism to describe a single-compartment neuron with sodium and potassium conductances. For the transient sodium current, the activation variable m is assumed fast and substituted by its steady-state function.

Wang XJ, Buzsáki G (1996) Gamma oscillation by synaptic inhibition in a hippocampal interneuronal network model. J. Neurosci. 16: 6402–6413.
