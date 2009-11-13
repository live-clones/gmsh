function [P, L, U] = kbihnf(A)

% [P, L, U] = kbihnf(A)
%
% Computes the integer Hermite normal form L such that 
% 
%   P*A = L*U
% 
% Uses external Kannan-Bachem implementation

%    Copyright (C) 3.11.2003 Saku Suuriniemi TUT/CEM
%
%    This program is free software; you can redistribute it and/or modify
%    it under the terms of the GNU General Public License as published by
%    the Free Software Foundation; either version 2 of the License, or
%    any later version.
%
%    This program is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%    GNU General Public License for more details.
%
%    You should have received a copy of the GNU General Public License
%    along with this program; if not, write to the Free Software
%    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

%   Saku Suuriniemi, TUT/Electromagetics
%   P.O.Box 692, FIN-33101 Tampere, Finland
%   saku.suuriniemi@tut.fi

  [i,j,v] = find(A);

  fid = fopen('hnf_temp.crd', 'w');
  fprintf(fid, '%g %g %g\n', size(A,1), size(A,2), length(i));
  if ~isempty(v)
    fprintf(fid, '%g %g %g\n', [i'; j'; v']);
  end
  fclose(fid);

  system ("./compute_normal_form -Hl hnf_temp.crd");

  load hnf_temp.left;
  P = zeros(hnf_temp(1,1), hnf_temp(1,2));
  for i = 2:size(hnf_temp,1)
    P(hnf_temp(i,1), hnf_temp(i,2)) = hnf_temp(i,3);
  end

  load hnf_temp.can;
  L = zeros(hnf_temp(1,1), hnf_temp(1,2));
  for i = 2:size(hnf_temp,1)
    L(hnf_temp(i,1), hnf_temp(i,2)) = hnf_temp(i,3);
  end

  load hnf_temp.right;
  U = zeros(hnf_temp(1,1), hnf_temp(1,2));
  for i = 2:size(hnf_temp,1)
    U(hnf_temp(i,1), hnf_temp(i,2)) = hnf_temp(i,3);
  end
