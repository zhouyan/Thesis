.PHONY : plot

.PHONY : clean

plot : Adaptive_Dist.pdf Adaptive_Proposal.pdf CESS_Iter_Mean.pdf CESS_Iter_Var.pdf CESS_Path_Var.pdf CESS_SMC_Var.pdf Fixed_Proposal.pdf MCMC_Iter_Var.pdf Particle_Iter_Var.pdf PET_MH_Diag_C.pdf PET_MH_Diag.pdf PET_MH_H_Path.pdf PET_MH_Path.pdf Typical_PET.pdf GMM_Resample.pdf bench-ocl-speedup-running.pdf bench-smp-speedup-running.pdf bench-ocl-time-running.pdf bench-smp-time-running.pdf

clean :
	rm -f *.aux *.log *.out *.fdb_latexmk *.synctex.gz *.pyg *.fls *busy*

Adaptive_Dist.pdf : Adaptive_Dist.tex
	latexmk -silent -f Adaptive_Dist.tex >/dev/null

Adaptive_Proposal.pdf : Adaptive_Proposal.tex
	latexmk -silent -f Adaptive_Proposal.tex >/dev/null

CESS_Iter_Mean.pdf : CESS_Iter_Mean.tex
	latexmk -silent -f CESS_Iter_Mean.tex >/dev/null

CESS_Iter_Var.pdf : CESS_Iter_Var.tex
	latexmk -silent -f CESS_Iter_Var.tex >/dev/null

CESS_Path_Var.pdf : CESS_Path_Var.tex
	latexmk -silent -f CESS_Path_Var.tex >/dev/null

CESS_SMC_Var.pdf : CESS_SMC_Var.tex
	latexmk -silent -f CESS_SMC_Var.tex >/dev/null

Fixed_Proposal.pdf : Fixed_Proposal.tex
	latexmk -silent -f Fixed_Proposal.tex >/dev/null

MCMC_Iter_Var.pdf : MCMC_Iter_Var.tex
	latexmk -silent -f MCMC_Iter_Var.tex >/dev/null

Particle_Iter_Var.pdf :  Particle_Iter_Var.tex
	latexmk -silent -f Particle_Iter_Var.tex >/dev/null

PET_MH_Diag_C.pdf : PET_MH_Diag_C.tex
	latexmk -silent -f PET_MH_Diag_C.tex >/dev/null

PET_MH_Diag.pdf : PET_MH_Diag.tex
	latexmk -silent -f PET_MH_Diag.tex >/dev/null

PET_MH_H_Path.pdf : PET_MH_H_Path.tex
	latexmk -silent -f PET_MH_H_Path.tex >/dev/null

PET_MH_Path.pdf : PET_MH_Path.tex
	latexmk -silent -f PET_MH_Path.tex >/dev/null

Typical_PET.pdf : Typical_PET.tex
	latexmk -silent -f Typical_PET.tex >/dev/null

GMM_Resample.pdf : GMM_Resample.tex
	latexmk -silent -f GMM_Resample.tex >/dev/null

bench-ocl-speedup-running.pdf : bench-ocl-speedup-running.tex
	latexmk -silent -f bench-ocl-speedup-running.tex >/dev/null

bench-smp-speedup-running.pdf : bench-smp-speedup-running.tex
	latexmk -silent -f bench-smp-speedup-running.tex >/dev/null

bench-ocl-time-running.pdf : bench-ocl-time-running.tex
	latexmk -silent -f bench-ocl-time-running.tex >/dev/null

bench-smp-time-running.pdf : bench-smp-time-running.tex
	latexmk -silent -f bench-smp-time-running.tex >/dev/null
